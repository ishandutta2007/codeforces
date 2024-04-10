program problem3;

procedure proc( var str: string );
var str2: string;
    i: longWord;
    bool: boolean;
begin
  bool := false;
  str2 := '';

  for i := 1 to length(str) do
  begin
    if ( str[i] <> ' ' ) or ( bool ) then
      str2 := str2 + str[i];
    if ( str[i] = '"' ) then
      bool := not bool;
  end;

  str := str2;
end;

function getMsg( str: string ): string;
var str2: string;
    i: longWord;
    bool: boolean;
begin
  bool := false;
  for i := 1 to length( str ) do
    if ( str[i] = '"' ) then
      bool := not bool
    else if ( bool ) then
      str2 := str2 + str[i];

  exit( str2 );
end;

var n, h, eh, i: longWord;
    str, t, t2: string;
    bool: boolean;

begin
  h := 0;
  bool := false;

  readln( n );
  for i := 1 to n do
  begin
    readln( str );
    proc( str );
    if ( length(str) >= 3 ) then
    begin
      if ( ( str[1] = 't' ) or ( str[1] = 'T' ) ) and ( ( str[2] = 'r' ) or ( str[2] = 'R' ) ) then
        inc( h )
      else if ( ( str[1] = 't' ) or ( str[1] = 'T' ) ) and ( ( str[2] = 'h' ) or ( str[2] = 'H' ) ) then
      begin
        eh := h;
        t := copy( str, 7, ( length(str) - 7 ) );
        bool := true;
      end
      else if ( ( str[1] = 'c' ) or ( str[1] = 'C' ) ) then
      begin
        if ( bool ) then
        begin
          if ( h = eh ) then
          begin
            t2 := copy( str, 7, ( pos( ',', str ) - 7 ) );
            if ( t2 = t ) then
            begin
              str := getMsg( str );
              writeln( str );
              halt;
            end
            else
              dec( eh );
          end;
        end;

        dec( h );
      end;
    end;
  end;

  writeln( 'Unhandled Exception' );
end.