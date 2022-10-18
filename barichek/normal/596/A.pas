uses math;
var
  a:array[1..2,1..4]of longint;
  n:longint;
  i:longint;
begin
  read(n);
  if n=1 then begin writeln(-1); halt; end;
  for i:=1 to n do
    read(a[1,i],a[2,i]);
  if (n=2) and ((a[1,1]-a[1,2])*(a[2,1]-a[2,2])=0) then begin writeln(-1); halt; end;

  if (a[1,1]-a[1,2])*(a[2,1]-a[2,2])<>0 then begin writeln(abs(a[1,2]-a[1,1])*abs(a[2,2]-a[2,1])); halt; end
  else if (a[1,1]-a[1,3])*(a[2,1]-a[2,3])<>0 then begin writeln(abs(a[1,1]-a[1,3])*abs(a[2,1]-a[2,3])); halt; end
  else begin writeln(abs(a[1,2]-a[1,3])*abs(a[2,2]-a[2,3])); halt; end;
end.