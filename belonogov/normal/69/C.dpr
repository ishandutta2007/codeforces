{$O-}
type art = record
  s: string;
  k: longint;
end;

type Trec =  record
  s: string;
  k: longint;
  a: array[1..100] of art;
end;


var
  a: array[1..100, 1..100] of longint;
  b: array[1..100] of string;
  rec: array[1..100] of Trec;
  qq, k, j1, n, m, q, i, j, uk, kk, kol: longint;
  s: string;

function nom(s: string): longint;
var
  i: longint; 
begin
  for i := 1 to n + m do
    if b[i] = s then nom := i;

end;
procedure prov(k: longint);
var
  i, j: longint;
  check: boolean;

begin
  for i := 1 to m do
  begin
    check := true;
    for j := 1 to rec[i].k do
      if rec[i].a[j].k > a[k, nom(rec[i].a[j].s)] then
        check := false;

    if check then
    begin
      for j := 1 to rec[i].k do
        a[k, nom(rec[i].a[j].s)] := a[k, nom(rec[i].a[j].s)] - rec[i].a[j].k;
      inc(a[k, nom(rec[i].s)]);
    end;  

  end;

end;
begin
   readln(k, n, m, q);
  for i := 1 to n do
    readln(b[i]);

  for i := 1 to m do
  begin
    readln(s);
    s := s + ',';
    j := 1;
    while s[j] <> ':' do
      inc(j);

    rec[i].s := copy(s, 1, j - 1);
    b[n + i] := rec[i].s;
    uk := 0;

    j := j + 2;
    while j < length(s) do
    begin
      j1 := j;
      while s[j] <> ' ' do
        inc(j);

      inc(uk);
      rec[i].a[uk].s := copy(s, j1, j - j1);
      inc(j);
      j1 := j;
      while (s[j] <> ',') and (j < length(s)) do
        inc(j);

      val(copy(s, j1, j - j1), rec[i].a[uk].k, qq);
      j := j + 2;
    end;
    rec[i].k := uk;
  end;
  {sort}
   for i := 1 to n + m do
     for j := 1 to n + m - i do
       if b[j] > b[j + 1] then
       begin
         s := b[j];
         b[j] := b[j + 1];
         b[j + 1] := s;
       end;
  {sort}
  for i := 1 to q do
  begin
    readln(s);
    j := 1;
    while s[j] <> ' ' do
      inc(j);

    val(copy(s, 1, j - 1), kk, qq);
    inc(a[kk, nom(copy(s, j + 1, length(s) - j))]);
    prov(kk);
  end;

  for i := 1 to k do
  begin
    kol := 0;
    for j := 1 to n + m do
      if a[i, j] <> 0 then inc(kol);

    writeln(kol);
    for j := 1 to n + m do
      if a[i, j] <> 0 then
        writeln(b[j], ' ', a[i ,j]);


  end;



end.