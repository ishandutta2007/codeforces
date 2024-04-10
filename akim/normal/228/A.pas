var a:array[1..4]of longint;
    i,f,z,o:longint;
begin
 readln(a[1],a[2],a[3],a[4]);
 for i:=1 to 3 do
  for f:=i+1 to 4 do
   if a[i]>a[f] then begin z:=a[i];a[i]:=a[f];a[f]:=z;end;
 for i:=2 to 4 do
  if a[i]=a[i-1] then inc(o);
 writeln(o);
end.