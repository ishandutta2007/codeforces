program problem4;

const wall  = '#';
      free  = '.';
      left  = 0;
      right = 1;
      up    = 2;
      down  = 3;

var a: array[ 0..16, 0..16 ] of char;
    s: array[ 1..16777216, 0..1 ] of longWord;
    b: array[0..16777216] of boolean;
    k, mask: longWord;

procedure snake( p: longWord; t: char );
var i, x, y, q: longWord;
begin
  x := p and 15;
  y := ( p shr 4 ) and 15;
  a[x][y] := t;
  for i := 0 to (k-2) do
  begin
    q := ( p shr ( 8 + (2*i) ) ) and 3;

    if ( q = left ) then
      dec( x )
    else if ( q = right ) then
      inc( x )
    else if ( q = up ) then
      dec( y )
    else
      inc( y );

    a[x][y] := t;
  end;
end;

procedure add( p, x, y, last, cnt: longWord; var r: longWord );
begin
  p := x + ( y shl 4 ) + ( last shl 8 ) + ( ( (p shr 8) and mask ) shl 10 );

  if ( not b[p] ) then
  begin
    inc( r );
    s[r][0] := p;
    s[r][1] := cnt;
    b[p] := true;
  end;
end;

var n, m, i, j, x, y, p, l, r: longWord;
    c: char;

begin
  fillchar( b, sizeOf(b), false );

  readln( n, m );
  for j := 1 to m do
  begin
    a[0][j] := wall;
    a[n+1][j] := wall;
  end;

  for i := 1 to n do
  begin
    a[i][0] := wall;
    a[i][m+1] := wall;

    for j := 1 to m do
    begin
      read( a[i][j] );
      if ( a[i][j] = '1' ) then
      begin
        x := i;
        y := j;
      end;
    end;

    readln();
  end;

  p := x + ( y shl 4 );
  j := 8;
  k := 0;
  while ( true ) do
  begin
    c := chr( ord( a[x][y] ) + 1 );
    a[x][y] := free;

    if      ( a[x-1][y] = c ) then
    begin
      p := p + ( left shl j );
      dec( x );
    end
    else if ( a[x+1][y] = c ) then
    begin
      p := p + ( right shl j );
      inc( x );
    end
    else if ( a[x][y-1] = c ) then
    begin
      p := p + ( up shl j );
      dec( y );
    end
    else if ( a[x][y+1] = c ) then
    begin
      p := p + ( down shl j );
      inc( y );
    end
    else
      break;

    inc( j, 2 );
    inc( k, 1 );
  end;

  mask := 0;
  for i := 1 to (k-1) do
    mask := ( mask shl 2 ) + 3;

  b[p] := true;
  l := 1;
  r := 1;
  s[1][0] := p;
  s[1][1] := 0;
  while ( l <= r ) do
  begin
    snake( s[l][0], wall );

    x := s[l][0] and 15;
    y := ( s[l][0] shr 4 ) and 15;

    if ( a[x-1][y] = '@' ) or ( a[x+1][y] = '@' ) or ( a[x][y-1] = '@' ) or ( a[x][y+1] = '@' ) then
    begin
      writeln( s[l][1] + 1 );
      halt;
    end;

    if ( a[x-1][y] = free ) then
      add( s[l][0], (x-1), y, right, (s[l][1]+1), r );
    if ( a[x+1][y] = free ) then
      add( s[l][0], (x+1), y, left, (s[l][1]+1), r );
    if ( a[x][y-1] = free ) then
      add( s[l][0], x, (y-1), down, (s[l][1]+1), r );
    if ( a[x][y+1] = free ) then
      add( s[l][0], x, (y+1), up, (s[l][1]+1), r );

    snake( s[l][0], free );
    inc( l );
  end;

  writeln( '-1' );
end.