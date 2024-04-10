program Problem2;
type tPoint = record
                x, y: int64;
              end;
     tLine = record
               cnt, sum: longWord;
               p1, p2: tPoint;
             end;

function NOD( a, b: longWord ): longWord;
var t: longWord;
begin
  if ( a < b ) then
  begin
    t := a;
    a := b;
    b := t;
  end;

  while ( b > 0 ) do
  begin
    t := b;
    b := a mod b;
    a := t;
  end;

  NOD := a;
end;

procedure getLastPoints( var lp1, lp2: tPoint; p1, p2: tPoint );
var dx, dy: longInt;
    k: qWord;
    t: tPoint;
begin
  if ( p1.y > p2.y ) then
  begin
    t := p1;
    p1 := p2;
    p2 := t;
  end
  else if ( p1.y = p2.y ) then
  begin
    lp1.x := 0;
    exit;
  end;

  dy := p2.y - p1.y;
  dx := p2.x - p1.x;
  k := NOD( abs(dx), abs(dy) );
  dx := dx div k;
  dy := dy div k;

  if ( p1.y mod dy ) > 0 then
  begin
    lp1.x := 0;
    exit;
  end;

  lp1.y := 0;
  lp1.x := p1.x - dx * ( p1.y div dy );

  k := ( 1005000000 - p2.y + dy - 1 ) div dy;
  lp2.x := p2.x + dx * k;
  lp2.y := p2.y + dy * k;
end;

var n, m, i, j, k, l_cnt: longWord;
    p: array[1..250] of tPoint;
    l: array[1..62500] of tLine;
    p1, p2: tPoint;
    bool: boolean;
    arr: array[1..1000000] of longWord;
    sum: qWord;

begin
  readln( n, m );
  for i := 1 to m do
    readln( p[i].x, p[i].y );

  for i := 1 to n do
    arr[i] := 1;

  l_cnt := 0;

  for i := 1 to (m-1) do
    for j := (i+1) to m do
    begin
      getLastPoints( p1, p2, p[i], p[j] );

      if ( p1.x > 0 ) and ( p1.x <= n ) then
      begin
        bool := true;
        for k := 1 to l_cnt do
          if ( l[k].p1.x = p1.x ) and ( l[k].p1.y = p1.y ) and ( l[k].p2.x = p2.x ) and ( l[k].p2.y = p2.y ) then
          begin
            inc( l[k].sum );
            if ( l[k].sum = l[k].cnt ) then
            begin
              inc( l[k].cnt );
              l[k].sum := 0;
            end;

            bool := false;
            break;
          end;

        if ( bool ) then
        begin
          inc( l_cnt );
          l[l_cnt].p1 := p1;
          l[l_cnt].p2 := p2;
          l[l_cnt].cnt := 2;
          l[l_cnt].sum := 0;
        end;
      end;

    end;

  for i := 1 to l_cnt do
    if ( l[i].cnt > arr[ l[i].p1.x ] ) then
      arr[ l[i].p1.x ] := l[i].cnt;

  sum := 0;
  for i := 1 to n do
    sum := sum + arr[i];

  writeln( sum );
end.