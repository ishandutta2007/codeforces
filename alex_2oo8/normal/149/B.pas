program problem2;

procedure addZeros( var str: string );
begin
  while ( length( str ) < 6 ) or ( str[6] <> ':' ) do
    str := '0' + str;
  while ( length( str ) < 11 ) do
    str := copy( str, 1, 6 ) + '0' + copy( str, 7, length( str ) - 6 );
end;

function minSystem( str: string ): byte;
var maxOrd, i: byte;

begin
  maxOrd := 0;

  for i := 1 to 11 do
  begin
    if ( i <> 6 ) and ( ord( str[i] ) > maxOrd ) then
    begin
      maxOrd := ord( str[i] );
    end;
  end;

  if ( maxOrd < 58 ) then
    minSystem := maxOrd - ord( '0' ) + 1
  else
    minSystem := maxOrd - ord( 'A' ) + 10 + 1;
end;

function calc( str: string; s: byte ): longWord;
var a, sum: longWord;
    i, n: byte;
begin
  a := 1;
  sum := 0;


  for i := 5 downTo 1 do
  begin
    if ( str[i] <= '9' ) then
      n := ord( str[i] ) - ord( '0' )
    else
      n := ord( str[i] ) - ord( 'A' ) + 10;
    sum := sum + ( n * a );
    a := a * s;
  end;

  calc := sum;
end;

function all( str: string ): boolean;
var b: boolean;
    i: byte;
begin
  b := true;

  for i := 1 to 11 do
    if ( ( i < 5 ) or ( ( i > 6 ) and ( i < 11 ) ) ) and ( str[i] <> '0' ) then
      b := false;
  if ( b ) then
  begin
    if not ( ( ( str[5] <= '9' ) or ( ( ord( str[5] ) - ord( 'A' ) + 10 ) < 24 ) ) and
             ( ( str[7] <= '9' ) or ( ( ord( str[5] ) - ord( 'A' ) + 10 ) < 60 ) ) ) then
       b := false;
  end;

  all := b;
end;

function no( str: string; min: byte ): boolean;
begin
  if ( calc( copy( str, 1, 5 ), min ) > 23 ) or
     ( calc( copy( str, 7, 5 ), min ) > 59 ) then
     no := true
  else
    no := false;
end;

var str: string;
    i, sys: word;
    minSys: byte;
    lastOk: boolean;

begin
  readln( str );
  addZeros( str );
  minSys := minSystem( str );

  if ( all( str ) ) then
    writeln( '-1' )
  else if ( no( str, minSys ) ) then
    writeln( '0' )
  else
  begin
    lastOk := true;
    sys := minSys;

    while ( lastOk ) do
    begin
      if ( calc( copy( str, 1, 5 ), sys ) < 24 ) and
         ( calc( copy( str, 7, 5 ), sys ) < 60 ) then
      begin
        write( sys, ' ' );
        inc( sys );
      end
      else
        lastOk := false;
    end;
  end;

end.