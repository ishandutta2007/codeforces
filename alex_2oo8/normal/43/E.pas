program problem5;

type tRec = record
              c, t, v: longWord;
            end;
     tTArr = array[1..10000] of tRec;
     tArr = array[1..100] of longWord;

procedure qsort( var arr: tTArr; l, r: longWord );
var i, j, med: longWord;
    t: tRec;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := arr[ (l+r) div 2 ].t;
    while ( i <= j ) do
    begin
      while ( arr[i].t < med ) do
        inc( i );
      while ( arr[j].t > med ) do
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

procedure qsortPArr( var arr, arr2, s_arr: tArr; l, r: longWord );
var i, j, med, t: longWord;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := arr[ (l+r) div 2 ];
    while ( i <= j ) do
    begin
      while ( s_arr[ arr[i] ] > s_arr[med] ) or ( ( s_arr[ arr[i] ] = s_arr[med] ) and ( arr2[ arr[i] ] < arr2[med] ) ) do
        inc( i );
      while ( s_arr[ arr[j] ] < s_arr[med] ) or ( ( s_arr[ arr[j] ] = s_arr[med] ) and ( arr2[ arr[j] ] > arr2[med] ) ) do
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

    qsortPArr( arr, arr2, s_arr, l, j );
    qsortPArr( arr, arr2, s_arr, i, r );
  end;
end;

function calc( var p_arr, lp_arr: tArr; n: longWord ): longWord;
var i, j, res: longWord;
begin
  res := 0;

  for i := 1 to (n-1) do
    for j := (i+1) to n do
      if ( ( p_arr[i] < p_arr[j] ) and ( lp_arr[i] > lp_arr[j] ) ) or ( ( p_arr[j] < p_arr[i] ) and ( lp_arr[j] > lp_arr[i] ) ) then
        inc( res );

  calc := res;
end;

var n, s, k, i, j, v, t, tsum, t_arr_n, ans: longWord;
    t_arr: tTArr;
    v_arr, s_arr, p_arr, p_arr2, lp_arr: tArr;

begin
  t_arr_n := 0;
  ans := 0;

  readln( n, s );
  for i := 1 to n do
  begin
    read( k, v, t );
    tsum := t;
    v_arr[i] := v;
    s_arr[i] := 0;
    p_arr[i] := i;
    lp_arr[i] := i;
    for j := 2 to k do
    begin
      read( v, t );
      inc( t_arr_n );
      t_arr[t_arr_n].c := i;
      t_arr[t_arr_n].v := v;
      t_arr[t_arr_n].t := tsum;
      inc( tsum, t );
    end;
    inc( t_arr_n );
    t_arr[t_arr_n].c := i;
    t_arr[t_arr_n].v := 0;
    t_arr[t_arr_n].t := tsum;
    readln();
  end;

  qsort( t_arr, 1, t_arr_n );

  for i := 1 to n do
    s_arr[i] := v_arr[i] * t_arr[1].t;
  qsortPArr( p_arr, lp_arr, s_arr, 1, n );
  for i := 1 to n do
    lp_arr[ p_arr[i] ] := i;
  v_arr[ t_arr[1].c ] := t_arr[1].v;
  i := 2;
  while ( i <= t_arr_n ) and ( t_arr[i].t = t_arr[i-1].t ) do
  begin
    v_arr[ t_arr[i].c ] := t_arr[i].v;
    inc( i );
  end;

  while ( i <= t_arr_n ) do
  begin
    for j := 1 to n do
      s_arr[j] := s_arr[j] + ( v_arr[j] * ( t_arr[i].t - t_arr[i-1].t ) );
    qsortPArr( p_arr, lp_arr, s_arr, 1, n );
    for j := 1 to n do
      p_arr2[ p_arr[j] ] := j;

    inc( ans, calc( p_arr2, lp_arr, n ) );

    v_arr[ t_arr[i].c ] := t_arr[i].v;
    inc( i );
    while ( i <= t_arr_n ) and ( t_arr[i].t = t_arr[i-1].t ) do
    begin
      v_arr[ t_arr[i].c ] := t_arr[i].v;
      inc( i );
    end;

    lp_arr := p_arr2;
  end;

  writeln( ans );
end.