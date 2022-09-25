program problem2;

var n, i, j, k, x, y, s, m: longWord;
    c: array[1..50] of longWord;
    a: array[ 1..50, 1..50 ] of longWord;
    ans: array[ 1..2500, 1..4 ] of longWord;

begin
  readln( n );
  s := 0;
  for i := 1 to n do
  begin
    read( c[i] );
    s := s + c[i];
  end;
  readln();

  for i := 1 to n do
  begin
    for j := 1 to c[i] do
      read( a[i][j] );
    readln();
  end;

  x := 1;
  y := 1;
  m := 0;
  for i := 1 to s do
  begin
    for j := x to n do
    begin
      for k := 1 to c[j] do
        if ( a[j][k] = i ) then
          break;
      if ( a[j][k] = i ) then
        break;
    end;

    if not ( ( x = j ) and ( y = k ) ) then
    begin
      inc( m );
      ans[m][1] := x;
      ans[m][2] := y;
      ans[m][3] := j;
      ans[m][4] := k;

      a[j][k] := a[x][y];
      a[x][y] := i;
    end;

    inc( y );
    if ( y > c[x] ) then
    begin
      inc( x );
      y := 1;
    end;
  end;

  writeln( m );
  for i := 1 to m do
    writeln( ans[i][1], ' ', ans[i][2], ' ', ans[i][3], ' ', ans[i][4] );
end.