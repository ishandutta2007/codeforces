program problem3;
type tRec = record
              a, prev, next: longWord;
            end;
     tArr = array[0..200000] of tRec;

var n_arr: array[1..200000] of longWord;

procedure delete( var arr: tArr; a: longWord );
var i: longWord;
begin
  i := n_arr[a];

  arr[ arr[i].next ].prev := arr[i].prev;
  arr[ arr[i].prev ].next := arr[i].next;
end;

var n, ans, i, j, k: longWord;
    m1, m2: tArr;

begin
  readln( n );

  m1[0].next := 1;
  for i := 1 to n do
  begin
    read( m1[i].a );
    m1[i].prev := i - 1;
    m1[i].next := i + 1;
  end;
  readln;

  m2[0].next := 1;
  for i := 1 to n do
  begin
    read( m2[i].a );
    m2[i].prev := i - 1;
    m2[i].next := i + 1;
    n_arr[ m2[i].a ] := i;
  end;

  ans := 0;
  k := 0;
  i := n;
  j := n;
  while ( true ) do
  begin
    while ( m1[i].a = m2[j].a ) do
    begin
      i := m1[i].prev;
      j := m2[j].prev;
      inc( k );

      if ( i = 0 ) and ( j = 0 ) then
      begin
        writeln( ans );
        halt;
      end;
    end;

    inc( ans, (k+1) );
    k := 0;

    delete( m2, m1[i].a );

    i := m1[i].prev;
  end;
end.