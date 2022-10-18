uses math;
var
  a:array[1..100,1..100]of longint;
  n:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    begin
      a[1,i]:=1;
      a[i,1]:=1;
    end;

  for i:=2 to n do
    for j:=2 to n do
      a[i,j]:=a[i-1,j]+a[i,j-1];

  writeln(a[n,n]);
end.]