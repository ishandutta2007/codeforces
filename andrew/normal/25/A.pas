var
 a:array[1..1000]of longint;
 sc1,sc2,i,j,n:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i]mod 2=1 then inc(sc1) else inc(sc2);
 end;
 if sc1=1 then
 begin
  for i:=1 to n do
  if a[i]mod 2=1 then begin writeln(i); halt; end;
 end
 else
 for i:=1 to n do
 if a[i]mod 2=0 then begin writeln(i); halt; end;
end.