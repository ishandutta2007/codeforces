uses math;
var
  a:array[1..2000]of longint;
  n,x,ans:longint;
  i,l:longint;
begin
  read(n,x);
  l:=1;
  ans:=0;
  for i:=1 to 2*n do
    read(a[i]);

  for i:=1 to n do
    begin
      inc(ans,(a[2*i-1]-l)mod x);
      l:=a[2*i]+1;
      inc(ans,a[2*i]-a[2*i-1]+1);
    end;
  writeln(ans);
end.