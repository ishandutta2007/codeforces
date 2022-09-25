program problem3;
type tArr = array[ 1..100000, 0..1 ] of longWord;

procedure qsort( var arr: tArr; l, r: longWord );
var med, i, j, t: longWord;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := arr[ ( l + r ) div 2 ][1];
    while ( i <= j ) do
    begin
      while ( arr[i][1] < med ) do
        inc( i );
      while ( arr[j][1] > med ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := arr[i][0];
        arr[i][0] := arr[j][0];
        arr[j][0] := t;
        t := arr[i][1];
        arr[i][1] := arr[j][1];
        arr[j][1] := t;

        inc( i );
        dec( j );
      end;
    end;
    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var n, i, j, k: longWord;
    a: tArr;
    commands: array[ 0..1, -1..50000 ] of longWord;

begin
  readln( n );
  for i := 1 to n do
  begin
    a[i][0] := i;
    read( a[i][1] );
  end;

  qsort( a, 1, n );

  commands[0][-1] := 0;
  commands[0][0] := 0;
  commands[1][-1] := 0;
  commands[1][0] := 0;

  if ( n mod 4 ) < 2 then
    k := n div 2
  else
    k := ( n div 2 ) - 1;
  for i := 1 to k do
  begin
    if ( commands[0][0] < commands[1][0] ) or ( ( commands[0][0] = commands[1][0] ) and ( commands[0][-1] < commands[1][-1] ) ) then
      j := 0
    else
      j := 1;
    inc( commands[j][0] );
    commands[j][ commands[j][0] ] := a[i][0];
    inc( commands[j][0] );
    commands[j][ commands[j][0] ] := a[n - i + 1][0];
    inc( commands[j][-1], ( a[i][1] + a[n-i+1][1] ) );
  end;

  for i := ( n - k ) downTo ( k + 1 ) do
  begin
    if ( commands[0][0] < commands[1][0] ) or ( ( commands[0][0] = commands[1][0] ) and ( commands[0][-1] < commands[1][-1] ) ) then
      j := 0
    else
      j := 1;
    inc( commands[j][0] );
    commands[j][ commands[j][0] ] := a[i][0];
  end;

  for i := 0 to 1 do
  begin
    writeln( commands[i][0] );
    write( commands[i][1] );
    for j := 2 to commands[i][0] do
      write( ' ', commands[i][j] );
    writeln;
  end;
end.