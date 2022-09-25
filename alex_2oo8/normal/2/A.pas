program problem1;
type tRec = record
              name: string;
              score, n: longInt;
              log: array[ 0..1000, 0..1 ] of longInt;
            end;
     tArr = array[1..1000] of tRec;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j: longWord;
    med, t: tRec;
begin
  if ( r > l ) then
  begin
    med := arr[ (l+r) div 2 ];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].score > med.score ) or ( ( arr[i].score = med.score ) and ( arr[i].n < med.n ) ) do
        inc( i );
      while ( arr[j].score < med.score ) or ( ( arr[j].score = med.score ) and ( arr[j].n > med.n ) ) do
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

var n, i, j, cnt, k: longWord;
    sc: longInt;
    str: string;
    chr: char;
    arr: tArr;

begin
  cnt := 0;

  readln( n );
  for i := 1 to n do
  begin
    str := '';
    read( chr );
    while ( chr <> ' ' ) do
    begin
      str := str + chr;
      read( chr );
    end;
    readln( sc );

    k := 0;
    for j := 1 to cnt do
      if ( arr[j].name = str ) then
      begin
        k := j;
        break;
      end;

    if ( k = 0 ) then
    begin
      inc( cnt );
      k := cnt;
      arr[k].name := str;
      arr[k].score := 0;
      arr[k].log[0][0] := 0;
      arr[k].n := 0;
    end;

    inc( arr[k].score, sc );
    inc( arr[k].log[0][0] );
    arr[k].log[ arr[k].log[0][0] ][0] := i;
    arr[k].log[ arr[k].log[0][0] ][1] := arr[k].score;
  end;

  qsort( arr, 1, cnt );

  k := 1;
  while ( k < cnt ) and ( arr[k+1].score = arr[k].score ) do
    inc( k );

  for i := 1 to k do
    with arr[i] do
    begin
      j := 1;
      while ( log[j][1] < score ) do
        inc( j );

      n := log[j][0];
    end;

  qsort( arr, 1, k );

  writeln( arr[1].name );
end.