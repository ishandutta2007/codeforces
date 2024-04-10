program problem1;

var n, m, cx, cy, i, j: longWord;
    str: string;
    x, y: array[0..2] of longWord;
    b: boolean;

begin
  readln( n, m );
  x[0] := 0;
  y[0] := 0;

  for i := 1 to n do
  begin
    readln( str );
    for j := 1 to m do
      if ( str[j] = '*' ) then
      begin
        inc( x[0] );
        x[ x[0] ] := j;
        inc( y[0] );
        y[ y[0] ] := i;
      end;
  end;

  for i := 1 to x[0] do
  begin
    b := true;
    for j := 1 to x[0] do
      if ( x[i] = x[j] ) and ( i <> j ) then
        b := false;

    if b then
    begin
      cx := x[i];
      break;
    end;
  end;

  for i := 1 to y[0] do
  begin
    b := true;
    for j := 1 to y[0] do
      if ( y[i] = y[j] ) and ( i <> j ) then
        b := false;

    if b then
    begin
      cy := y[i];
      break;
    end;
  end;

  writeln( cy, ' ', cx );
end.