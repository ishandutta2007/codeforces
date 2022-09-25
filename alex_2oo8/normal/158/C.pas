program problem3;
type tArr = array[1..10100] of char;

procedure printDir( dir: tArr; length: word );
var i: word;
begin
  for i := 1 to length do
    write( dir[i] );
  if length > 1 then
    write('/');
  writeln;
end;

procedure setDir( var dir: tArr; var dir_length: word; new_dir: string );
var i: byte;
begin
  if ( new_dir[1] = '/' ) then
    dir_length := 0
  else if ( dir_length > 1 ) then
  begin
    inc( dir_length );
    dir[dir_length] := '/';
  end;
  for i := 1 to length( new_dir ) do
  begin
    if ( i < length( new_dir ) ) and ( new_dir[i] = '.' ) and ( new_dir[i+1] = '.' ) then
    begin
      dir_length := dir_length - 2;
      while ( dir[dir_length+1] <> '/' ) and ( dir_length > 1 ) do
        dec( dir_length );
    end
    else if ( new_dir[i] <> '.' ) and not ( ( new_dir[i] = '/' ) and ( dir_length = 1 ) ) then
    begin
      inc( dir_length );
      dir[dir_length] := new_dir[i];
    end;
  end;
end;

var n, i: byte;
    dir: tArr;
    dir_length: word;
    c: string[3];
    new_dir: string;

begin
  dir[1] := '/';
  dir_length := 1;
  readln( n );
  for i := 1 to n do
  begin
    read( c );
    if ( c = 'pwd' ) then
    begin
      printDir( dir, dir_length );
      readln;
    end
    else
    begin
      readln( new_dir );
      setDir( dir, dir_length, new_dir );
    end;
  end;
end.