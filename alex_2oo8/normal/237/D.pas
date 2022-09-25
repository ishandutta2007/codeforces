program problem4;

type tRec = record
              u, v, next: longWord;
            end;
var e: array[1..200000] of tRec;
    first, cnt: array[1..100000] of longWord;
    n: longWord;

procedure DFS( u, p, k: longWord );
var i: longWord;
begin
  i := first[u];
  while ( i > 0 ) do
  begin
    if ( e[i].v <> p ) then
    begin
      writeln( k, ' ', (i mod n) );
      DFS( e[i].v, u, (i mod n) );
    end;

    i := e[i].next;
  end;
end;

var i, j, k: longWord;

begin
  fillchar( first, sizeOf(first), 0 );
  fillchar( cnt, sizeOf(cnt), 0 );

  readln( n );
  for i := 1 to (n-1) do
  begin
    readln( e[i].u, e[i].v );
    e[i].next := first[ e[i].u ];
    first[ e[i].u ] := i;

    e[i+n].u := e[i].v;
    e[i+n].v := e[i].u;
    e[i+n].next := first[ e[i].v ];
    first[ e[i].v ] := i + n;

    inc( cnt[ e[i].v ] );
    inc( cnt[ e[i].u ] );
  end;

  writeln( (n-1) );
  for i := 1 to (n-1) do
    writeln( '2 ', e[i].u, ' ', e[i].v );

  i := 1;
  while ( cnt[i] > 1 ) do
    inc( i );

  DFS( e[ first[i] ].v, i, (first[i] mod n) );
end.