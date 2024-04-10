program problem4;
uses math;

type tArr = array[1..400000] of longWord;

var arr: tArr;

procedure qsort( var sorted: tArr; l, r: longWord );
var i, j, t, med: longWord;

begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := sorted[ (l+r) div 2 ];
    while ( i <= j ) do
    begin
      while ( arr[ sorted[i] ] < arr[med] ) or ( ( arr[ sorted[i] ] = arr[med] ) and ( sorted[i] < med ) ) do
        inc(i);
      while ( arr[ sorted[j] ] > arr[med] ) or ( ( arr[ sorted[j] ] = arr[med] ) and ( sorted[j] > med ) ) do
        dec(j);

        if ( i <= j ) then
        begin
          t := sorted[i];
          sorted[i] := sorted[j];
          sorted[j] := t;

          inc(i);
          dec(j);
        end;
    end;

    qsort( sorted, l, j );
    qsort( sorted, i, r );
  end;
end;

var n, k, i, j, m: longWord;
    sorted, sorted_i: tArr;
    ans: qWord;

begin
  ans := 0;

  readln( n, k );
  for i := 1 to n do
  begin
    read( arr[i] );
    sorted[i] := i;
  end;

  qsort( sorted, 1, n );

  for i := 1 to n do
    sorted_i[ sorted[i] ] := i;

  m := n + 1;
  for i := (n-k+1) downTo 1 do
  begin
    j := sorted_i[i] + k - 1;
    if ( j <= n ) and ( arr[ sorted[j] ] = arr[i] ) then
      m := min( m, sorted[j] );

    inc( ans, (n-m+1) );
  end;

  writeln( ans );
end.