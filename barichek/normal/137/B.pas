uses math;
var
  a,b:array[1..100000]of longint;
  n,ans:longint;
  i:longint;
begin
  read(n);
  ans:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      b[i]:=0;
    end;

  for i:=1 to n do
    inc(b[a[i]]);
  for i:=1 to n do
    if b[i]=0 then inc(ans);
  writeln(ans);
end.