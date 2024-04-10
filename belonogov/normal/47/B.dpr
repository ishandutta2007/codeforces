var
  a: array[1..3] of string;
  ab, bc, ac, i: longint;
  q: char;

begin
  readln(a[1]);
  readln(a[2]);
  readln(a[3]);
  ab := 0;
  bc := 0;
  ac := 0;
  for i := 1 to 3 do
    if a[i, 2] = '>' then
    begin
      a[i, 2] := '<';
      q := a[i, 1];
      a[i, 1] := a[i, 3];
      a[i, 3] := q;
    end;


  for i := 1 to 3 do
    if ((a[i, 1]  = 'A') and (a[i, 3] = 'B')) then
      ab := 1;

  for i := 1 to 3 do
    if ((a[i, 1]  = 'B') and (a[i, 3] = 'C')) then
      bc := 1;

  for i := 1 to 3 do
    if ((a[i, 1]  = 'A') and (a[i, 3] = 'C')) then
      ac := 1;

  if (ab = 0) and (bc = 0) and (ac = 0) then writeln('CBA');

  if (ab = 0) and (bc = 0) and (ac = 1) then writeln('Impossible');

  if (ab = 0) and (bc = 1) and (ac = 0) then writeln('BCA');

  if (ab = 0) and (bc = 1) and (ac = 1) then writeln('BAC');

  if (ab = 1) and (bc = 0) and (ac = 0) then writeln('CAB');

  if (ab = 1) and (bc = 0) and (ac = 1) then writeln('ACB');

  if (ab = 1) and (bc = 1) and (ac = 0) then writeln('Impossible');

  if (ab = 1) and (bc = 1) and (ac = 1) then writeln('ABC');

end.