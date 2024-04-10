program problem4;
type tArr = array[ 0..100000, 0..1 ] of longWord;

procedure qsort( var arr: tArr; l, r: longWord );
var med, i, j: longWord;
begin
  if ( r > l ) then
  begin
    med := arr[ (l+r) div 2 ][1];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i][1] > med ) do
        inc( i );
      while ( arr[j][1] < med ) do
        dec( j );

      if ( i <= j ) then
      begin
        arr[0] := arr[i];
        arr[i] := arr[j];
        arr[j] := arr[0];

        inc( i );
        dec( j );
      end;
    end;

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var n, k, i, m: longWord;
    b, sum: qWord;
    a: tArr;

begin
  readln( n, k, b );

  for i := 1 to n do
  begin
    read( a[i][1] );
    a[i][0] := i;
  end;

  qsort( a, 1, (n-1) );

  m := n;
  sum := 0;

  for i := 1 to (k-1) do
  begin
    inc( sum, a[i][1] );
    if ( a[i][0] < m ) then
      m := a[i][0];
  end;

  if ( sum >= b ) then
    writeln( '1' )
  else if ( (sum+a[k][1]) <= b ) then
    writeln( n )
  else
  begin

    i := k;
    b := b - sum;
    while ( i <= n ) and ( a[i][1] > b ) do
    begin
      if ( a[i][0] < m ) then
        m := a[i][0];

      inc( i );
    end;

    writeln( m );

  end;
end.