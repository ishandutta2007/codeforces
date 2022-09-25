program problem5;
uses dos;

type tRec = record
              top, bot, left, right, t: longWord;
            end;
     tArr = array[0..5000] of tRec;

function calc( arr: tArr; i: longWord ): longWord;
var res: longWord;
begin
  res := 0;
  while ( i <> 0 ) do
  begin
    inc( res );
    arr[ arr[i].top ].bot := arr[i].bot;
    arr[ arr[i].bot ].top := arr[i].top;
    arr[ arr[i].left ].right := arr[i].right;
    arr[ arr[i].right ].left := arr[i].left;
    if ( arr[i].t = 1 ) then
      i := arr[i].top
    else if ( arr[i].t = 2 ) then
      i := arr[i].right
    else if ( arr[i].t = 3 ) then
      i := arr[i].bot
    else if ( arr[i].t = 4 ) then
      i := arr[i].left;
  end;

  calc := res;
end;

var n, m, cnt, ans, ans_cnt, l, i, j: longWord;
    cols: array[1..5000] of longWord;
    arr: tArr;
    chr: char;

begin
  cnt := 0;
  readln( n, m );

  for i := 1 to m do
    cols[i] := 0;

  for i := 1 to n do
  begin
    l := 0;
    for j := 1 to m do
    begin
      read( chr );
      if ( chr <> '.' ) then
      begin
        inc( cnt );
        arr[cnt].top := cols[j];
        arr[ cols[j] ].bot := cnt;
        cols[j] := cnt;
        arr[cnt].left := l;
        arr[l].right := cnt;
        l := cnt;
        if ( chr = 'U' ) then
          arr[cnt].t := 1
        else if ( chr = 'R' ) then
          arr[cnt].t := 2
        else if ( chr = 'D' ) then
          arr[cnt].t := 3
        else if ( chr = 'L' ) then
          arr[cnt].t := 4;
      end;
    end;
    arr[l].right := 0;
    readln();
  end;
  for i := 1 to m do
    arr[ cols[i] ].bot := 0;

  ans := 0;
  ans_cnt := 0;
  for i := 1 to cnt do
  begin
    l := calc( arr, i );
    if ( l > ans ) then
    begin
      ans := l;
      ans_cnt := 1;
    end
    else if ( l = ans ) then
      inc( ans_cnt );
  end;

  writeln( ans, ' ', ans_cnt );
end.