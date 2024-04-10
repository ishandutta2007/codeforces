program problem3;

var n, m, cnt: longWord;
    arr: array[ 1..50, 1..50 ] of char;
    painted: array[ 1..2500, 0..1 ] of longWord;
    checked: array[ 1..50, 1..50 ] of longWord;

function check(): boolean;
var i, j, i2, k, sum: longWord;
    stack: array[ 1..2500, 0..1 ] of longWord;
begin
  k := 0;
  for i2 := 1 to cnt do
  begin
    inc( k );
    checked[ painted[i2][0] ][ painted[i2][1] ] := k;

    if ( i2 = 1 ) then
    begin
      stack[1][0] := painted[2][0];
      stack[1][1] := painted[2][1];
    end
    else
    begin
      stack[1][0] := painted[1][0];
      stack[1][1] := painted[1][1];
    end;

    i := 1;
    j := 1;
    sum := 1;
    while ( i <= j ) do
    begin
      if ( stack[i][0] > 1 ) and ( arr[ stack[i][0] - 1 ][ stack[i][1] ] = '#' ) and ( checked[ stack[i][0] - 1 ][ stack[i][1] ] <> k ) then
      begin
        inc( j );
        stack[j][0] := stack[i][0] - 1;
        stack[j][1] := stack[i][1];
        checked[ stack[i][0] - 1 ][ stack[i][1] ] := k;
        inc( sum );
      end;

      if ( stack[i][1] > 1 ) and ( arr[ stack[i][0] ][ stack[i][1] - 1 ] = '#' ) and ( checked[ stack[i][0] ][ stack[i][1] - 1 ] <> k ) then
      begin
        inc( j );
        stack[j][0] := stack[i][0];
        stack[j][1] := stack[i][1] - 1;
        checked[ stack[i][0] ][ stack[i][1] - 1 ] := k;
        inc( sum );
      end;

      if ( stack[i][0] < n ) and ( arr[ stack[i][0] + 1 ][ stack[i][1] ] = '#' ) and ( checked[ stack[i][0] + 1 ][ stack[i][1] ] <> k ) then
      begin
        inc( j );
        stack[j][0] := stack[i][0] + 1;
        stack[j][1] := stack[i][1];
        checked[ stack[i][0] + 1 ][ stack[i][1] ] := k;
        inc( sum );
      end;

      if ( stack[i][1] < m ) and ( arr[ stack[i][0] ][ stack[i][1] + 1 ] = '#' ) and ( checked[ stack[i][0] ][ stack[i][1] + 1 ] <> k ) then
      begin
        inc( j );
        stack[j][0] := stack[i][0];
        stack[j][1] := stack[i][1] + 1;
        checked[ stack[i][0] ][ stack[i][1] + 1 ] := k;
        inc( sum );
      end;

      inc( i );
    end;

    if ( sum < cnt ) then
      exit( true );
  end;

  exit( false );
end;

var i, j: longWord;

begin
  cnt := 0;
  readln( n, m );
  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      read( arr[i][j] );
      if ( arr[i][j] = '#' ) then
      begin
        inc( cnt );
        painted[cnt][0] := i;
        painted[cnt][1] := j;
      end;
      checked[i][j] := 0;
    end;
    readln;
  end;

  if ( cnt < 3 ) then
    writeln( '-1' )
  else if ( check() ) then
    writeln( '1' )
  else
    writeln( '2' );
end.