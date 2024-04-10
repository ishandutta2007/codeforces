program problem2;
uses math;

type tArr = array[1..100000] of longWord;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j, med, t: longWord;
begin
  if ( l <r  ) then
  begin
    i := l;
    j := r;
    med := arr[ l + random(r-l+1) ];
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

var n, m, i, k: longWord;
    a: tArr;
    s, ans: array[0..100000] of qWord;
    l, j: int64;

begin
  readln( n );
  for i := 1 to n do
    read( a[i] );
  readln();

  qsort( a, 1, n );

  s[0] := 0;
  for i := 1 to n do
    s[i] := s[i-1] + a[i];

  for i := 1 to 100000 do
  begin
    ans[i] := 0;
    k := 0;
    l := n;
    j := 1;
    while ( (l+j-1) > 0 ) do
    begin
      ans[i] := ans[i] + ( k * ( s[l+j-1] - s[ max( (l-1), 0 ) ] ) );

      j := j * i;
      l := l - j;
      inc( k );
    end;
  end;

  readln( m );
  for i := 1 to m do
  begin
    read( k );
    write( ans[k], ' ' );
  end;
end.