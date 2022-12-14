var
 s1,s2:ansistring;
 ch1,ch2,n,i,x1,x2,ans:longint;
begin
 readln(n);
 readln(s1);
 readln(s2);

 for i:=1 to n do
  if (s1[i]<>s2[i]) then
  begin
   ch1:=i;
   break;
  end;
 for i:=n downto 1 do
  if s1[i]<>s2[i] then
  begin
   ch2:=i;
   break;
  end;
 s1:=copy(s1,ch1,ch2-ch1+1);
 s2:=copy(s2,ch1,ch2-ch1+1);
 if s2[1]+s1=s2+s1[length(s1)]then inc(ans);
 if s1+s2[length(s2)]=s1[1]+s2 then inc(ans);
 //writeln(s2,'-',s1);
 writeln(ans);
end.