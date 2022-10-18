uses math;
var
  n:longint;
  i:longint;
begin
  read(n);
  writeln;
  for i:=1 to n div 4 do
    write('abcd');
  case n mod 4 of
    1: write('a');
    2: write('ab');
    3: write('abc');
  end;
end.