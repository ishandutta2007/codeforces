uses math;
var
  n:longint;
  i:longint;
begin
  readln(n);

  n:=n-7;
  write('ROYGBIV');

  for i:=1 to n div 4 do
    write('GBIV');
  case n mod 4 of
    1: write('G');
    2: write('GB');
    3: write('GBI');
  end;
end.