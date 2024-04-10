uses math;
var
  a:array[1..100000]of longint;
  n:int64;
  i,j,k:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (a[i]=a[j]+a[k]) and (i<>j) and (j<>k) and (k<>i) then begin writeln(i,' ',j,' ',k); halt; end;

  writeln(-1);
end.