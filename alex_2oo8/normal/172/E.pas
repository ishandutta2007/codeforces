program problem5;
type tagName = string[10];

var str: ansistring;
    lastStr: tagName;
    i, j, html_length, n, css_length, ans, level, arr_i: longWord;
    html: array[ 1..500000 ] of tagName;
    css: array[ 1..200 ] of tagName;
    arr: array[ 0..205, 0..1 ] of longWord;
    close: boolean;

begin
  lastStr := '';
  html_length := 0;
  close := false;

  readln( str );
  for i := 1 to length( str ) do
  begin
    if ( str[i] = '>' ) then
    begin
      if ( lastStr <> '' ) then
      begin
        inc( html_length );
        html[ html_length ] := lastStr;
        lastStr := '';
      end;

      if close then
      begin
        inc( html_length );
        html[ html_length ] := '/';
        close := false;
      end;
    end
    else if ( str[i] = '/' ) then
      close := true
    else if ( str[i] in ['a'..'z'] ) and ( not close ) then
      lastStr := lastStr + str[i];
  end;

  readln( n );
  for i := 1 to n do
  begin
    lastStr := '';
    css_length := 0;

    readln( str );
    for j := 1 to length( str ) do
    begin
      if ( str[j] in ['a'..'z'] ) then
        lastStr := lastStr + str[j];
      if ( str[j] = ' ' ) or ( j = length( str ) ) then
      begin
        inc( css_length );
        css[ css_length ] := lastStr;
        lastStr := '';
      end;
    end;

    ans := 0;
    level := 0;
    arr_i := 0;
    arr[0][0] := 1;
    arr[0][1] := 0;

    for j := 1 to html_length do
    begin
      if ( html[j] = '/' ) then
      begin
        dec( level );
        if ( level < arr[ arr_i ][1] ) then
          dec( arr_i );
      end
      else
      begin
        inc( level );
        if ( html[j] = css[ arr[ arr_i ][0] ] ) then
        begin
          if ( arr[arr_i][0] = css_length ) then
            inc( ans )
          else
          begin
            inc( arr_i );
            arr[ arr_i ][0] := arr[ arr_i - 1 ][0] + 1;
            arr[ arr_i ][1] := level;
          end;
        end;
      end;
    end;

    writeln( ans );
  end;
end.