var
 a:array[1..1000,1..1000]of longint;
 s:ansistring;
 q,i,j,n,sc,c:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   read(a[i,j]);
   if i=j then inc(sc,a[i,j]);
   if sc=2 then sc:=0;
  end;
  readln;
 end;
 readln(q);
 s:='';
 for i:=1 to q do
 begin
  read(c);
  if c=3 then s:=s+chr(sc+48) else sc:=1-sc;
  readln;
 end;
 writeln(s);
end.