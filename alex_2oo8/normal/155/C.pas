program problem3;
uses math;

var str, s: ansistring;
    k, i, ci, li, ans: longWord;
    d: array['a'..'z'] of char;
    chr: char;
    arr: array[ 0..1, 'a'..'z' ] of longWord;

begin
  ci := 0;
  li := 1;
  for chr := 'a' to 'z' do
  begin
    d[chr] := '.';
    arr[ci][chr] := 0;
  end;

  readln( str );
  readln( k );
  for i := 1 to k do
  begin
    readln( s );
    d[ s[1] ] := s[2];
    d[ s[2] ] := s[1];
  end;

  for i := 1 to length(str) do
  begin
    ci := 1 - ci;
    li := 1 - li;

    for chr := 'a' to 'z' do
      arr[ci][chr] := arr[li][chr] + 1;
    for chr := 'a' to 'z' do
      if ( chr <> d[ str[i] ] ) then
        arr[ci][ str[i] ] := min( arr[ci][ str[i] ], arr[li][chr] );
  end;

  ans := length(str);
  for chr := 'a' to 'z' do
    ans := min( ans, arr[ci][chr] );

  writeln( ans );
end.