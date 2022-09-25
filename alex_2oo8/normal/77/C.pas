program taskI8;

type tRec = record
              u, v, nextU, nextV: longWord;
            end;

var a: array[1..100000] of tRec;
    k: array[1..100000] of longWord;
    next: array[1..100000] of longWord;
    h: array[1..100000] of qWord;

procedure add( w: longWord; val: qWord; var n: longWord );
var i: longWord;
begin
  inc( n );
  i := n;

  while ( i <> 1 ) and ( val > h[ w + (i div 2) ] ) do
  begin
    h[w+i] := h[ w + (i div 2) ];
    i := i div 2;
  end;

  h[w+i] := val;
end;

procedure del( w: longWord; var n: longWord );
var i, iMin, x: longWord;
begin
  x := h[w+n];
  dec( n );
  i := 1;

  while ( (2*i) <= n ) do
  begin
    if ( (2*i) = n ) or ( h[ w + (2*i) ] > h[ w + (2*i+1) ] ) then
      iMin := 2 * i
    else
      iMin := 2 * i + 1;

    if ( x > h[ w + iMin ] ) then
      break;

    h[ w + i ] := h[ w + iMin ];
    i := iMin;
  end;

  h[ w + i ] := x;
end;

function calc( u, p, w: longWord ): qWord;
var res, sum: qWord;
    i, j, v, cnt: longWord;
begin
  res := 1;
  sum := 0;
  cnt := 0;

  i := next[u];
  while ( i <> 0 ) do
  begin
    if ( a[i].u = u ) then
    begin
      v := a[i].v;
      j := a[i].nextU;
    end
    else
    begin
      v := a[i].u;
      j := a[i].nextV;
    end;

    if ( v <> p ) then
    begin
      dec( k[v] );
      add( w, calc( v, u, (w+cnt) ), cnt );
      sum := sum + k[v];
    end;

    i := j;
  end;

  while ( cnt > 0 ) and ( k[u] > 0 ) do
  begin
    res := res + h[w+1] + 1;
    dec( k[u] );

    del( w, cnt );
  end;

  if ( k[u] >= sum ) then
  begin
    res := res + ( 2 * sum );
    k[u] := k[u] - sum;
  end
  else
  begin
    res := res + ( 2 * k[u] );
    k[u] := 0;
  end;

  calc := res;
end;

var n, m, i, j: longWord;
    ans: qWord;

begin
  readln( n );
  for i := 1 to n do
  begin
    read( k[i] );
    next[i] := 0;
  end;
  readln();

  for i := 1 to (n-1) do
  begin
    readln( a[i].u, a[i].v );

    a[i].nextU := next[ a[i].u ];
    a[i].nextV := next[ a[i].v ];

    next[ a[i].u ] := i;
    next[ a[i].v ] := i;
  end;

  readln( i );

  ans := calc( i, 0, 0 ) - 1;

  writeln( ans );
end.