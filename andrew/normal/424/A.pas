var
 s:ansistring;
 a:array[1..1000000]of char;
 d,sch,b,c,n,m,su,k,i,j:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i]='X' then inc(sch);
 end;
 k:=n div 2;
 if sch>k then
 begin
  writeln(sch-k);
  d:=sch-k;
  for i:=1 to d do
  for j:=1 to n do if a[j]='X' then begin a[j]:='x'; break end;
 end;
 if sch<k then
 begin
  writeln(k-sch);
  d:=k-sch;
  for i:=1 to d do
  for j:=1 to n do if a[j]='x' then begin a[j]:='X'; break end;
 end;
 if sch=k then writeln(0);
 for i:=1 to n do write(a[i]);
end.