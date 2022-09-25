program problem1;

function sum( str: string ): byte;
var summ, i: byte;
begin
  summ := 0;

  for i := 1 to length( str ) do
  begin
    summ := summ + ( ord( str[i] ) - ord( '0' ) );
  end;

  sum := summ;
end;

function lucky( str: string ): boolean;
var b: boolean;
    i: byte;
begin
  b := true;

  for i := 1 to length( str ) do
    if ( str[i] <> '4' ) and ( str[i] <> '7' ) then
    begin
      b := false;
      break;
    end;

  lucky := b;
end;

var n: byte;
    str: string;

begin
  readln( n );
  readln( str );
  if ( sum( copy( str, 1, n div 2 ) ) = sum( copy( str, ( n div 2 ) + 1, n div 2 ) ) ) and ( lucky( str ) ) then
    writeln( 'YES' )
  else
    writeln( 'NO' );
end.