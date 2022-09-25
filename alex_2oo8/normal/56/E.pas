program problem5;

type tRec = record
              x, h, z: longInt;
            end;
     tArr = array[1..100001] of tRec;
     tSortedArr = array[1..100001] of longWord;

procedure qsort( const arr: tArr; var sorted: tSortedArr; l, r: longWord );
var i, j, med, t: longInt;
begin
  if ( l <= r ) then
  begin
    i := l;
    j := r;
    med := arr[ sorted[ (l+r) div 2 ] ].x;
    while ( i <= j ) do
    begin
      while ( arr[ sorted[i] ].x < med ) do
        inc( i );
      while ( arr[ sorted[j] ].x > med ) do
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

    qsort( arr, sorted, l, j );
    qsort( arr, sorted, i, r );
  end;
end;

var n, i, m: longWord;
    arr: tArr;
    sorted: tSortedArr;
    a: array[ 1..100000, 0..1 ] of longInt;

begin
  readln( n );
  for i := 1 to n do
  begin
    readln( arr[i].x, arr[i].h );
    sorted[i] := i;
  end;

  qsort( arr, sorted, 1, n );
  sorted[n+1] := n + 1;
  arr[n+1].x := 1000000000;
  arr[n+1].h := 0;

  m := 0;
  for i := 1 to (n+1) do
  begin
    while ( m > 0 ) and ( a[m][1] < arr[ sorted[i] ].x ) do
    begin
      arr[ sorted[ a[m][0] ] ].z := i - a[m][0];
      dec( m );
    end;

    inc( m );
    a[m][0] := i;
    a[m][1] := arr[ sorted[i] ].x + arr[ sorted[i] ].h - 1;
  end;

  for i := 1 to n do
    write( arr[i].z, ' ' );
end.