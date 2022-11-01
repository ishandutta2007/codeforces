var
  a: array[1..10,1..10] of char;
  FFF, III, TTT, i, j, ans, kitten: integer;
begin
    readln(FFF,III,TTT);

    for i := 1 to FFF do
    begin
      for j := 1 to III-1 do
        read(a[i][j]);
      readln(a[i][III]);
    end;

    ans:=0;
    for j := 1 to III do
    begin
      kitten:=0;

      for i := 1 to FFF do
        if a[i][j]='Y' then
          inc(kitten);

      if kitten>=TTT then
        inc(ans);
    end;

    write(ans);
end.