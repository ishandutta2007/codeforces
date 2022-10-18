uses math;
var
  a,b:ansistring;
  ans:longint;
  i:longint;
begin
  readln(a);
  readln(b);
  ans:=1;

  for i:=1 to length(b) do
    if b[i]=a[ans] then inc(ans);
  writeln(ans);
end.