uses math;
var
  i,k,n,w,a:longint;
begin
  read(k,n,w);
  a:=0;
  for i:=1 to w do
                inc(a,i);
  k:=k*a;
  k:=k-n;
  if k<0 then k:=0;
  writeln(k);
end.