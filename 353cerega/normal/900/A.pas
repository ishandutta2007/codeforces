VAR
  a, b, i, r, n: LONGINT;
BEGIN
  READLN(n);
  FOR i := 1 TO n DO
    BEGIN
    READLN(a,b);
    IF a>0
    THEN
      r := r+1;
    END;
  IF (n-2<r) or (r<2)
  THEN
    WRITELN('Yes')
  ELSE
    WRITELN('No');
END.