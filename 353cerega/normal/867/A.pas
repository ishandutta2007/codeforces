VAR
  n, i: LONGINT;
  Ch, Ch1: CHAR;
BEGIN
  READLN(n);
  READ(Ch);
  FOR i := 2 TO n DO
    READ(Ch1);
  IF (Ch='S') AND (Ch1='F')
  THEN
    WRITELN('YES')
  ELSE
    WRITELN('NO');
END.