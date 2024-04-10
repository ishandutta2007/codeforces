program problem3;
type tArr = array[1..105] of longWord;

function min( a, b: longWord ): longWord;
begin
  if ( a < b ) then
    min := a
  else
    min := b;
end;

var planets: array[ 1..15, 1..105, 0..2 ] of longWord;
    m: longWord;

function calc( a, b: longWord ): tArr;
var sum: array[1..105] of longInt;
    sorted: tArr;

procedure qsort( l, r: longWord );
var i, j, med, t: longInt;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := sum[ sorted[ (l+r) div 2 ] ];

    while ( i <= j ) do
    begin
      while ( sum[ sorted[i] ] < med ) do
        inc( i );
      while ( sum[ sorted[j] ] > med ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := sorted[i];
        sorted[i] := sorted[j];
        sorted[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsort( l, j );
    qsort( i, r );
  end;
end;

var i: longWord;

begin
  for i := 1 to m do
  begin
    sum[i] := planets[b][i][1] - planets[a][i][0];
    sorted[i] := i;
  end;

  qsort( 1, m );

  calc := sorted;
end;

var n, k, i, j, y, ans, a, b, res: longInt;
    str: string;
    max: tArr;

begin
  readln( n, m, k );

  for i := 1 to n do
  begin
    readln( str );
    for j := 1 to m do
      readln( planets[i][j][0], planets[i][j][1], planets[i][j][2] );
  end;

  ans := 0;

  for i := 1 to n do
    for j := 1 to n do
      if ( i <> j ) then
      begin
        max := calc( i, j );
        res := 0;
        b := k;
        for y := m downTo 1 do
        begin
          if ( ( planets[j][ max[y] ][1] - planets[i][ max[y] ][0] ) < 0 ) then
            break;

          if ( b > planets[i][ max[y] ][2] ) then
          begin
            res := res + ( planets[i][ max[y] ][2] * ( planets[j][ max[y] ][1] - planets[i][ max[y] ][0] ) );
            b := b - planets[i][ max[y] ][2];
          end
          else
          begin
            res := res + ( b * ( planets[j][ max[y] ][1] - planets[i][ max[y] ][0] ) );
            break;
          end;
        end;

        if ( res > ans ) then
          ans := res;
      end;

  writeln( ans );
end.