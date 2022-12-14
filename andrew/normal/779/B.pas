var
 s,s1:ansistring;
 ch1,ch2,k,i,j,n,m,sc,dl:Longint;
begin
 readln(n,k);
 ch1:=1;
 for i:=1 to k do ch1:=ch1*10;
 str(n,s);
 dl:=length(s);
 if n<ch1 then begin writeln(length(s)-1); halt; end;
 while true do
 begin
  val(s,ch2);
  if ch2 mod ch1=0 then break;
  if ch2<ch1 then begin writeln(dl-1); halt; end;
  for i:=length(s) downto 1 do  if s[i]<>'0'then begin delete(s,i,1); break; end;
 end;
 writeln(dl-length(s));
end.