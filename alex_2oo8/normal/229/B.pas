program problem2;

const inf = trunc( 2.0e+9 );

type tERec = record
               v, w, next: longWord;
             end;
     tRec = record
              d, i: longWord;
              b: boolean;
            end;

var h: array[0..100000] of tRec;
    p: array[1..100000] of longWord;
    t: array[1..100000] of longWord;
    firstT: array[1..100001] of longWord;
    hN: longWord;

procedure del();
var i, iMin: longWord;
begin
  p[ h[1].i ] := 0;

  dec( hN );
  i := 1;
  while ( (2*i) <= hN ) do
  begin
    if ( (2*i) = hN ) or ( h[2*i].d < h[2*i+1].d ) then
      iMin := 2 * i
    else
      iMin := 2 * i + 1;

    if ( h[hN+1].d < h[iMin].d ) then
      break;

    h[i] := h[iMin];
    p[ h[i].i ] := i;
    i := iMin;
  end;

  h[i] := h[hN+1];
  p[ h[i].i ] := i;
end;

procedure swap( a, b: longWord );
var x: tRec;
begin
  x := h[a];
  h[a] := h[b];
  h[b] := x;

  p[ h[a].i ] := a;
  p[ h[b].i ] := b;
end;

procedure change( i, val: longWord );
var iMin: longWord;
begin
  h[i].d := val;
  while ( (2*i) <= hN ) do
  begin
    if ( (2*i) = hN ) or ( h[2*i].d < h[2*i+1].d ) then
      iMin := 2 * i
    else
      iMin := 2 * i + 1;

    if ( h[i].d < h[iMin].d ) then
      break;

    swap( i, iMin );
    i := iMin;
  end;

  while ( i > 1 ) and ( h[i].d < h[i div 2].d ) do
  begin
    swap( i, ( i div 2 ) );
    i := i div 2;
  end;
end;

function calc( i, d: longWord ): longWord;
var j: longWord;
begin
  j := firstT[i];
  while ( j < firstT[i+1] ) and ( t[j] <= d ) do
  begin
    if ( t[j] = d ) then
      inc( d );

    inc( j );
  end;

  calc := d;
end;

var n, m, i, j, k, d, x: longWord;
    next: array[1..100000] of longWord;
    e: array[1..200000] of tERec;

begin
  fillchar( next, sizeOf(next), 0 );

  readln( n, m );
  for i := 1 to m do
  begin
    readln( e[i].v, e[m+i].v, e[i].w );
    e[i].next := next[ e[m+i].v ];
    next[ e[m+i].v ] := i;

    e[m+i].w := e[i].w;
    e[m+i].next := next[ e[i].v ];
    next[ e[i].v ] := m + i;
  end;

  firstT[1] := 1;
  for i := 1 to n do
  begin
    read( k );
    firstT[i+1] := firstT[i] + k;

    for j := 1 to k do
      read( t[ firstT[i] + j - 1 ] );
    readln();
  end;

  h[0].d := 0;
  for i := 1 to n do
  begin
    h[i].i := i;
    h[i].d := inf;
    h[i].b := false;
    p[i] := i;
  end;
  h[1].d := 0;
  hN := n;

  while ( hN > 0 ) and ( h[1].d < inf ) do
  begin
    i := h[1].i;
    d := h[1].d;

    if ( i = n ) then
    begin
      writeln( d );
      halt;
    end;

    if ( not h[1].b ) then
    begin
      h[1].b := true;
      change( 1, calc( i, d ) );
      continue;
    end;

    del();

    j := next[i];
    while ( j > 0 ) do
    begin
      if ( not h[ p[ e[j].v ] ].b ) and ( ( d + e[j].w ) < h[ p[ e[j].v ] ].d ) then
        change( p[ e[j].v ], ( d + e[j].w ) );

      j := e[j].next;
    end;
  end;

  writeln( '-1' );
end.