uses math;
var
  a,b,c:longint;
  i:longint;
begin
  read(a,b,c);
  for i:=0 to c div a do
    if (c-i*a) mod b=0 then begin writeln('YES'); halt; end;

  writeln('NO')
end.