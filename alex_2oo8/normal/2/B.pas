program problem2;
uses math;

type tRec = record
              cnt: longWord;
              str: ansistring;
            end;

var n: longWord;
    arr: array[ 1..1000, 1..1000 ] of longWord;

function cnt( a, b: longWord ): longWord;
var ans: longWord;
begin
  ans := 0;
  while ( ( a mod b ) = 0 ) and ( a > 0 ) do
  begin
    inc( ans );
    a := a div b;
  end;

  cnt := ans;
end;

function calc( x: longWord ): tRec;
var m: array[ 0..1000, 0..1000 ] of tRec;
    cnt_arr: array[ 1..1000, 1..1000 ] of longWord;

procedure proc( a, b: longWord );
begin
  if ( m[a-1][b].cnt < m[a][b-1].cnt ) then
  begin
    m[a][b].cnt := cnt_arr[a][b] + m[a-1][b].cnt;
    m[a][b].str := m[a-1][b].str + 'D';
  end
  else
  begin
    m[a][b].cnt := cnt_arr[a][b] + m[a][b-1].cnt;
    m[a][b].str := m[a][b-1].str + 'R';
  end;

  m[a-1][b-1].str := '';
end;

var i, j: longWord;
begin
  for i := 1 to n do
  begin
    for j := 1 to n do
      cnt_arr[i][j] := cnt( arr[i][j], x );
    m[i][0].cnt := 99999;
    m[0][i].cnt := 99999;
  end;

  m[0][1].cnt := 0;
  m[0][1].str := '';

  for i := 1 to n do
    for j := i to n do
    begin
      proc( i, j );
      proc( j, i );
    end;

  m[n][n].str := copy( m[n][n].str, 2, (length( m[n][n].str ) - 1) );

  exit( m[n][n] );
end;

var ans1, ans2, ans3: tRec;
    i, j, k: longWord;
    bool: boolean;

begin
  bool := false;

  readln( n );
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      read( arr[i][j] );
      if ( not bool ) and ( arr[i][j] = 0 ) then
      begin
        bool := true;
        ans3.cnt := 1;
        ans3.str := '';
        for k := 2 to j do
          ans3.str := ans3.str + 'R';
        for k := 2 to i do
          ans3.str := ans3.str + 'D';
        for k := 1 to (n-j) do
          ans3.str := ans3.str + 'R';
        for k := 1 to (n-i) do
          ans3.str := ans3.str + 'D';
      end;
    end;
    readln;
  end;

  ans1 := calc(2);
  ans2 := calc(5);

  if ( ans1.cnt > ans2.cnt ) then
    ans1 := ans2;
  if bool and ( ans1.cnt > ans3.cnt ) then
    ans1 := ans3;

  writeln( ans1.cnt );
  writeln( ans1.str );
end.