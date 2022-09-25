program problem3;
type tRec = record
              str: string;
              cnt: longWord;
            end;

var n, i, j, cnt: longWord;
    arr: array[1..100000] of tRec;
    str: string;
    bool: boolean;

begin
  cnt := 0;

  readln( n );
  for i := 1 to n do
  begin
    readln( str );
    bool := true;
    for j := 1 to cnt do
      if( arr[j].str = str ) then
      begin
        inc( arr[j].cnt );
        writeln( str, arr[j].cnt );
        bool := false;
        break;
      end;

    if ( bool ) then
    begin
      writeln( 'OK' );
      inc( cnt );
      arr[cnt].str := str;
      arr[cnt].cnt := 0;
    end;
  end;
end.