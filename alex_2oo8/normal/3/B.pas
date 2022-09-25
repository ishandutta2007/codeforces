program problem2;
uses math;

type tArr = array[ 1..100001, 0..3 ] of longWord;
     tRec = record
              cnt: longWord;
              a: tArr;
            end;

procedure qsort( var arr: tArr; l, r: longWord );
var med, i, j: longWord;
begin
  if ( r > l ) then
  begin
    med := arr[ (l+r) div 2 ][3];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i][3] > med ) do
        inc( i );
      while ( arr[j][3] < med ) do
        dec( j );

      if ( i <= j ) then
      begin
        arr[100001] := arr[i];
        arr[i] := arr[j];
        arr[j] := arr[100001];

        inc( i );
        dec( j );
      end;
    end;

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var n, v, i, t, p, sum: longWord;
    arr: array[1..2] of tRec;
    sorted: tArr;

begin
  arr[1].cnt := 0;
  arr[2].cnt := 0;

  readln( n, v );

  for i := 1 to n do
  begin
    readln( t, p );
    inc( arr[t].cnt );
    arr[t].a[ arr[t].cnt ][0] := i;
    arr[t].a[ arr[t].cnt ][3] := p;
  end;

  qsort( arr[1].a, 1, arr[1].cnt );

  if ( ( v mod 2 ) = 1 ) and ( arr[1].cnt > 0 ) then
  begin
    sum := arr[1].a[1][3];
    t := arr[1].a[1][0];
  end;

  for i := 1 to arr[2].cnt do
  begin
    sorted[i][0] := 1;
    sorted[i][1] := arr[2].a[i][0];
    sorted[i][3] := arr[2].a[i][3];
  end;

  p := arr[2].cnt;

  if ( ( v mod 2 ) = 1 ) then
    i := 2
  else
    i := 1;
  while ( i < arr[1].cnt ) do
  begin
    inc( p );
    sorted[p][0] := 2;
    sorted[p][1] := arr[1].a[i  ][0];
    sorted[p][2] := arr[1].a[i+1][0];
    sorted[p][3] := arr[1].a[i  ][3] + arr[1].a[i+1][3];

    inc( i, 2 );
  end;

  if ( i = arr[1].cnt ) then
  begin
    inc( p );
    sorted[p][0] := 1;
    sorted[p][1] := arr[1].a[i][0];
    sorted[p][3] := arr[1].a[i][3];
  end;

  qsort( sorted, 1, p );

  for i := 1 to min( p, (v div 2) ) do
    inc( sum, sorted[i][3] );

  writeln( sum );

  if ( ( v mod 2 ) = 1 ) and ( arr[1].cnt > 0 ) then
    write( t, ' ' );

  for i := 1 to min( p, (v div 2) ) do
    for t := 1 to sorted[i][0] do
      write( sorted[i][t], ' ' );
end.