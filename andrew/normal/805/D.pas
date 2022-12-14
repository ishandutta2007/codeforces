var
 scb,sc1,sc,i,j,n,m,k,ans:longint;
 s:ansistring;
begin
 readln(s);
 n:=length(s);
 for i:=length(s) downto 2 do if s[i]='b' then
 begin
  inc(sc);
  if s[i-1]='a' then
  begin
   //dec(sc);
   sc:=sc mod(1000000007);
   ans:=(ans+sc)mod(1000000007);
   sc:=(sc*2)mod (1000000007);
  end;
 end else
 begin
  if(i<>n)and(s[i+1]='b')then continue;
  sc:=sc mod(1000000007);
   ans:=(ans+sc)mod(1000000007);
   sc:=(sc*2)mod (1000000007);
 end;
 if(s[1]='a')and(n>1)and(s[2]='a') then
 begin
  sc:=sc mod(1000000007);
  ans:=(ans+sc)mod(1000000007);
  sc:=(sc*2)mod (1000000007);
 end;
// writeln(sc);
 writeln(ans);
end.