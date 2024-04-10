program problem2;
type rec = record
             pl_name: string[11];
             points: longWord;
           end;
     tArr = array[1..1000] of rec;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j, med: longWord;
    t: rec;
begin
  if ( l < r ) then
  begin
    med := arr[ (l+r) div 2 ].points;
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].points < med ) do
        inc( i );
      while ( arr[j].points > med ) do
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

var players: tArr;
    i, j, cnt, n, p, k: longWord;
    chr: string[1];
    pl_name: string[11];

begin
  cnt := 0;

  readln( n );
  for i := 1 to n do
  begin
    pl_name := '';
    read( chr );
    while ( chr <> ' ' ) do
    begin
      pl_name := pl_name + chr;
      read( chr );
    end;
    readln( p );

    k := 0;
    for j := 1 to cnt do
      if ( players[j].pl_name = pl_name ) then
      begin
        k := j;
        break;
      end;

    if ( k = 0 ) then
    begin
      inc( cnt );
      k := cnt;
      players[k].pl_name := pl_name;
      players[k].points := 0;
    end;

    if ( players[k].points < p ) then
      players[k].points := p;
  end;

  qsort( players, 1, cnt );

  writeln( cnt );
  k := 1001;
  j := 0;
  for i := cnt downTo 1 do
  begin
    write( players[i].pl_name, ' ' );

    if ( players[i].points < k ) then
    begin
      k := players[i].points;
      j := i;
    end;

    if ( j >= ( (cnt*99+99) div 100 ) ) then
      writeln( 'pro' )
    else if ( j >= ( (cnt*9+9) div 10 ) ) then
      writeln( 'hardcore' )
    else if ( j >= ( (cnt*4+4) div 5 ) ) then
      writeln( 'average' )
    else if ( j >= ( (cnt*1+1) div 2 ) ) then
      writeln( 'random' )
    else
      writeln( 'noob' );
  end;
end.