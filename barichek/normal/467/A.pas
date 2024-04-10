uses math;
var
  n,p,q,ans:longint;
  i:longint;
begin
  read(n);
  ans:=0;

  for i:=1 to n do
    begin
      read(p,q);
      if q-p>1 then inc(ans);
    end;
  writeln(ans);
end.