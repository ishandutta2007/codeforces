program problem4;

type tArr = array[1..100000] of longWord;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j, med, t: longWord;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := arr[ (l+r) div 2 ];
    while ( i <= j ) do
    begin
      while ( arr[i] < med ) do
        inc( i );
      while ( arr[j] > med ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var n, i, j, m, ln, cnt: longWord;
    k, sum: qWord;
    a, arr: tArr;

begin
  sum := 0;

  readln( n, k );
  for i := 1 to n do
  begin
    read( a[i] );
    arr[i] := a[i];
    sum := sum + a[i];
  end;

  if ( sum < k ) then
  begin
    writeln( '-1' );
    halt;
  end
  else if ( sum = k ) then
    halt;

  qsort( a, 1, n );

  ln := n;
  m := 0;
  i := 1;
  while ( k > 0 ) do
  begin
    cnt := 1;
    while ( i < n ) and ( a[i+1] = a[i] ) do
    begin
      inc( i );
      inc( cnt );
    end;

    if ( ( ln * (a[i]-m) ) < k ) then
    begin
      k := k - ( ln * (a[i]-m) );
      m := a[i];
      ln := ln - cnt;
      inc( i );
    end
    else
    begin
      m := m + ( k div ln );
      k := k mod ln;
      break;
    end;
  end;

  if ( k = 0 ) then
  begin
    for i := 1 to n do
      if ( arr[i] > m ) then
        write( i, ' ' );
  end
  else
  begin
    inc( m );
    ln := 0;
    i := 0;
    while ( ln < k ) do
    begin
      inc( i );
      if ( arr[i] >= m ) then
        inc( ln );
    end;

  for j := (i+1) to n do
    if ( arr[j] >= m ) then
      write( j, ' ' );

  for j := 1 to i do
    if ( arr[j] > m ) then
      write( j, ' ' );

  end;
end.