program problem2;

function calc( n: longWord ): string;
begin
  if ( n > 26 ) then
    calc := calc( (n-1) div 26 ) + chr( ( ( (n-1) mod 26 ) + 1 ) + ord( 'A' ) - 1 )
  else
    calc := chr( n + ord( 'A' ) - 1 );
end;

function check( str: string ): boolean;
var k: longWord;
begin
  if ( str[1] <> 'R' ) then
    exit( false );

  k := 3;
  while ( str[k] in ['0'..'9'] ) and ( k <= length( str ) ) do
    inc( k );

  if ( k < length( str ) ) and ( str[k] = 'C' ) and ( str[k-1] in ['0'..'9'] ) and ( str[k+1] in ['0'..'9'] ) then
    exit( true )
  else
    exit( false );
end;

var n, x, y, i, j, k, a: longWord;
    str: string;

begin
  readln( n );

  for i := 1 to n do
  begin
    readln( str );

    if ( check( str ) ) then
    begin
      k := pos( 'C', str );
      val( copy( str, 2, ( k - 2 ) ), x );
      val( copy( str, ( k + 1 ), ( length( str ) - k ) ), y );

      writeln( calc( y ), x );
    end
    else
    begin
      k := 1;
      while not ( str[k+1] in ['0'..'9'] ) do
        inc( k );
      val( copy( str, (k+1), ( length( str ) - k ) ), x );

      y := 0;
      a := 1;
      for j := k downTo 1 do
      begin
        inc( y, ( a * ( ord( str[j] ) - ord('A') + 1 ) ) );
        a := a * 26;
      end;

      writeln( 'R', x, 'C', y );
    end;

  end;
end.