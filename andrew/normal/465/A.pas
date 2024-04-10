var
 s:ansistring;
 n,i,sc:longint;
begin
 readln(n);
 readln(s);
 for i:=1 to n do
 begin
  inc(sc);
  if s[i]='0' then break;
 end;
 writeln(sc);
end.