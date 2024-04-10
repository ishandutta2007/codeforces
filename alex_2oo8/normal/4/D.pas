program problem4;
type tRec = record
              next, cnt: longWord;
            end;
     tArr = array[ 0..5000, 0..2 ] of longWord;
     tDP = array[1..5000] of tRec;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j: longWord;
    med: array[1..2] of longWord;
begin
  if ( r > l ) then
  begin
    med[1] := arr[ (l+r) div 2 ][1];
    med[2] := arr[ (l+r) div 2 ][2];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i][1] < med[1] ) or ( ( arr[i][1] = med[1] ) and ( arr[i][2] < med[2] ) ) do
        inc( i );
      while ( arr[j][1] > med[1] ) or ( ( arr[j][1] = med[1] ) and ( arr[j][2] > med[2] ) ) do
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

procedure print( var arr: tArr; var dp: tDP; n: longWord );
begin
  if ( n > 0 ) then
  begin
    print( arr, dp, dp[n].next );
    write( arr[n][0], ' ' );
  end;
end;

var n, w, h, cnt, wi, hi, max, maxi, i, j, ans, ansi: longWord;
    arr: tArr;
    dp: tDP;

begin
  readln( n, w, h );

  cnt := 0;
  for i := 1 to n do
  begin
    readln( wi, hi );
    if ( wi > w ) and ( hi > h ) then
    begin
      inc( cnt );
      arr[cnt][0] := i;
      arr[cnt][1] := wi;
      arr[cnt][2] := hi;
    end;
  end;

  qsort( arr, 1, cnt );

  ans := 0;
  ansi := 0;

  for i := 1 to cnt do
  begin
    max := 0;
    maxi := 0;

    for j := (i-1) downTo 1 do
      if ( arr[i][1] > arr[j][1] ) and ( arr[i][2] > arr[j][2] ) and ( dp[j].cnt > max ) then
      begin
        max := dp[j].cnt;
        maxi := j;
      end
      else if ( j <= max ) then
        break;

    dp[i].cnt := max + 1;
    dp[i].next := maxi;

    if ( dp[i].cnt > ans ) then
    begin
      ans := dp[i].cnt;
      ansi := i;
    end;
  end;

  writeln( ans );
  if ( ans > 0 ) then
    print( arr, dp, ansi );
end.