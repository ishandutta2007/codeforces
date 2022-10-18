uses math;
var
  n:longint;
  i:longint;
begin
  read(n);
  n:=n*2;

  for i:=1 to 500 do
    if (n mod i=0) and (n div i=i+1) then begin writeln('YES'); halt; end;
  writeln('NO');
end.