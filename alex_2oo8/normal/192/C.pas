program problem3;
uses math;

var n, ans, i: longWord;
    arr: array[ 'a'..'z', 'a'..'z' ] of longWord;
    str: string;
    chr, chr2: char;

begin
  ans := 0;
  for chr := 'a' to 'z' do
    for chr2 := 'a' to 'z' do
      arr[chr][chr2] := 0;

  readln( n );

  for i := 1 to n do
  begin
    readln( str );

    for chr := 'a' to 'z' do
      if ( arr[chr][ str[1] ] > 0 ) and ( arr[chr][ str[ length(str) ] ] < ( arr[chr][ str[1] ] + length(str) ) ) then
      begin
        arr[chr][ str[ length(str) ] ] := arr[chr][ str[1] ] + length(str);
        if ( chr = str[ length(str) ] ) then
          ans := max( ans, arr[chr][ str[ length(str) ] ] );
      end;

    if ( arr[ str[1] ][ str[ length(str) ] ] < length(str) ) then
    begin
      arr[ str[1] ][ str[ length(str) ] ] := length(str);
      if ( str[1] = str[ length(str) ] ) then
        ans := max( ans, length(str) );
    end;
  end;

  writeln( ans );
end.