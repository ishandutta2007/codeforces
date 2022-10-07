{$O-}
var
  a: array[1..40000, 0..300] of longint;
  b: array[1..1000] of longint;
  rez: array[1..300, 0..300] of longint;
  k, n, i, j, j1, kol, d, kol1, kol2: longint;
  q: boolean;

begin
  read(n);
  for i := 1 to (n * (n - 1)) div 2 do
  begin
    read(k);
    a[i, 0] := k;
    for j := 1 to k  do
      read(a[i, j]);
  end;
 if n = 2 then
  begin
    writeln(1, ' ', a[1, 1]);
    write(a[1, 0] - 1, ' ');
    for i := 2 to a[1, 0] do
      write(a[1, i], ' ');
    exit;
  end;

 d := a[1, 1];
  kol := 0;
  for i := 2 to (n * (n - 1)) div 2 do
  begin
    q := false;
    for j := 1 to a[i, 0] do
      if a[i, j] = d then q := true;
    if q then
    begin
      inc(kol);
      b[kol] := i;
    end;
  end;

  kol1 := 0;
  for i := 1 to a[1, 0] do
  begin
    q := false;
    for j := 1 to a[b[1], 0] do
      if a[1, i] = a[b[1], j] then
        q := true;

    if q then
    begin
      inc(kol1);
      rez[1, kol1] := a[1, i];
    end;
  end;
  rez[1, 0] := kol1;

  for i := 1 to kol do
  begin
    kol1 := 0;
    for j := 1 to a[b[i], 0] do
    begin
      q := true;
      for j1 := 1 to rez[1, 0] do
        if rez[1, j1] = a[b[i], j] then q := false;
      if q then
      begin
        inc(kol1);
        rez[i + 1, kol1] := a[b[i], j];
      end;
    end;
    rez[i + 1, 0] := kol1;
  end;
  kol2 := 0;
  for i := 1 to a[1, 0] do
  begin
    q := true;
    for j := 1 to rez[1, 0] do
      if a[1, i] = rez[1, j] then q := false;
    if q then
    begin
      inc(kol2);
      rez[n, kol2] := a[1, i];
    end;
  end;
  rez[n, 0] := kol2;

  for i := 1 to n do
  begin
    write(rez[i, 0] , ' ');
    for j :=  1 to rez[i, 0] do
      write(rez[i, j], ' ');
    writeln;
  end;


end.