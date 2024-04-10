uses math;
var
  a:array[1..100000]of longint;
  n,ans:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n do
    for j:=i+1 to n do
      if (a[i]<>0) and (a[i]=a[j]) then begin inc(ans); a[i]:=0; a[j]:=0; end;
  writeln(ans div 2);
end.