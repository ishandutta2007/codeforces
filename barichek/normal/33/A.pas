uses math;
var
  a:array[1..100000]of longint;
  n,m,k,l,r,ans:int64;
  i,j:longint;
begin
  read(n,m,k);
  for i:=1 to m do
    a[i]:=1000000;

  for i:=1 to n do
    begin
      read(l,r);
      a[l]:=min(a[l],r);
    end;

  for i:=1 to m do
    inc(ans,a[i]);

  writeln(min(ans,k));
end.