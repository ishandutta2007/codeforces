VAR
  i, j, n, m, ans: LONGINT;
  count, p: INT64;
  d, t: ARRAY[0..200000] OF INT64;
BEGIN
  d[0] := 1;
  READLN(n,p,m);
  FOR i := 1 TO n DO
    READLN(d[i],t[i]);
  t[n+1] := -p;
  d[n+1] := m;
  FOR i := 1 TO n+1 DO
    BEGIN
      IF count<0
      THEN
        BEGIN
          ans := ans+d[i]-d[i-1];
        END
      ELSE
        IF ((d[i]-d[i-1])*p-count)>0
        THEN
          ans := ans+(((d[i]-d[i-1])*p-count-1) DIV p)+1;
      count := count-(d[i]-d[i-1])*p+t[i];
    END;
  IF count<0
  THEN
    ans := ans+1;
  WRITELN(ans);
END.