program problem2;
type tArr = array[1..4] of longInt;

var n, i, cnt: longWord;
    s, j, l: byte;
    a: tArr;

begin
  a[1] := 0;
  a[2] := 0;
  a[3] := 0;
  a[4] := 0;

  readln( n );
  for i := 1 to n do
  begin
    read( s );
    inc( a[s] );
  end;
  readln;

  cnt := a[4];
  for i := 3 downTo 1 do
  begin
    j := 4 - i;
    while ( a[i] > 0 ) do
    begin
      dec( a[i] );
      while ( a[j] = 0 ) and ( j > 1 ) do
        dec( j );
      l := 4 - i;
      while ( l >= j ) do
      begin
        dec( a[j] );
        l := l - j;
      end;
      inc( cnt );
    end;
  end;

  writeln( cnt );
end.